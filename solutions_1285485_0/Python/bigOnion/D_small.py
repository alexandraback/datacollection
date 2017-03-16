import time

directory = 'C:/users/hai/my projects/google code jam/2012/qualification/D/'

from math import sqrt

def solve (f_in, f_out):
    T = int(f_in.readline())
    for i in range(1,T+1):
        print ('Test Case : ',i)
        H, W, D = [int(x) for x in f_in.readline().split()]
        mat = []
        for line in range(H):
            mat.append(list(f_in.readline().replace('\n','')))
        res = solve_for_one_matrix(mat, D)
        f_out.write('Case #' + str(i) + ': ' + str(res) + '\n')






def gcd (v_speed, h_speed):
    assert v_speed != 0
    assert h_speed != 0
    a = abs(v_speed)
    b = abs(h_speed)
    while a != 0:
        a,b = b%a,a
    return b



def enlarge_matrix (mat, scale):
    assert scale %2 == 0
    height = len(mat)
    width = len(mat[0])
    #mat2 = [['.'] * (width*scale) for x in range(height*scale)]
    for i in range(height):
        for j in range(width):
            p = mat[i][j]
            if p == 'X':
                location_y = i*scale+scale//2
                location_x = j*scale+scale//2
            #elif p == '#':
            #    for t in range(scale):
            #        for s in range(scale):
            #            mat2[i*scale+t][j*scale+s] = '#'
    return len(mat[0])*scale, len(mat)*scale, location_x, location_y

def make_n_moves (n, width, height, scale, location_x, location_y, x_speed, y_speed):
    for i in range(n):
        assert x_speed !=0 
        assert location_x >=scale
        assert location_x <=width-scale
        
        if x_speed < 0 and location_x == scale:
            x_speed = -x_speed
        elif location_x == width-scale and x_speed > 0:
            x_speed = -x_speed

        location_x += x_speed

    for i in range(n):
        assert y_speed != 0
        assert location_y >=scale
        assert location_y <=height-scale
        
        if location_y == scale and y_speed < 0:
            y_speed = -y_speed
        elif location_y == height-scale and y_speed > 0:
            y_speed = -y_speed

        location_y += y_speed

    return location_x, location_y, x_speed, y_speed
         
    
def make_one_move (width, height, scale, location_x, location_y, x_speed, y_speed):
    assert x_speed !=0 and y_speed != 0
    assert location_x >=scale
    assert location_y >=scale
    assert location_x <=width-scale
    assert location_y <=height-scale
    
    if x_speed < 0 and location_x == scale:
        x_speed = -x_speed
    elif location_x == width-scale and x_speed > 0:
        x_speed = -x_speed
    if location_y == scale and y_speed < 0:
        y_speed = -y_speed
    elif location_y == height-scale and y_speed > 0:
        y_speed = -y_speed
        
            
    return location_x+x_speed, location_y+y_speed, x_speed, y_speed



def solve_for_one_matrix (mat, D):
    print (time.ctime())
    count = 0
    print_matrix(mat)
    print ('D = ', D)
    print ('Rays : ')

    good_directions = []
    width, height, location_x, location_y = enlarge_matrix(mat,2)

    # direction down
    if (height-2) - location_y <= D:
        good_directions.append ((0,1))

    # direction up
    if location_y-2 <=D:
        good_directions.append ((0,-1))

    #direction right
    if (width-2) - location_x <= D:
        good_directions.append((1,0))

    #direction left
    if location_x-2 <=D:
        good_directions.append((-1,0))

    print (good_directions)

    # diagonal directions
    for p in range(1, D*2+1):
        for q in range(1, p+1):
            if gcd (p,q) !=1:
                continue
            scale = p*q*2

            move_distance = sqrt(p**2 + q**2)
            if move_distance == round(move_distance):
                allowed_moves = D*scale // int(move_distance)
            else:
                allowed_moves = int(D*scale / move_distance)

            if allowed_moves < scale:
                continue

            width, height, original_location_x, original_location_y = enlarge_matrix(mat,scale)


            #print ('DEBUG: ',p,q,D,allowed_moves)
            
            arr = [(p,q),(-p,q),(p,-q),(-p,-q),(q,p),(-q,p),(q,-p),(-q,-p)]
            arr = unique(arr)
            for direction in arr:

                #print ('DEBUG:',direction)
                count_moves = 0
                x_speed, y_speed = direction
                continue_in_this_direction = True
                location_x = original_location_x
                location_y = original_location_y
                for i in range(allowed_moves//(scale//2)):
                    retval = make_n_moves(scale//2, width, height, scale, location_x, location_y, x_speed, y_speed)
                    count_moves += scale//2
                    location_x, location_y, x_speed, y_speed = retval
                    if location_x == original_location_x and location_y == original_location_y:
                        good_directions.append((direction[0],direction[1], count_moves, allowed_moves, allowed_moves//(scale//2)*(scale//2)))
                        #print (good_directions[-1], end= ', ')
                        break


    print()
    #print(good_directions)
    count = len(good_directions)
    print (count)
    return count


def unique(arr):
    arr2 = []
    for i in arr:
        if i not in arr2:
            arr2.append(i)
    return arr2

def print_matrix (mat):
    for line in mat:
        print (''.join(line))



def main_run():
    import os
    filenames = [x for x in os.listdir (directory)]
    filenames = [x for x in filenames if x.endswith('.in')]
    l1 = [(os.stat(directory+x).st_mtime, x) for x in filenames]
    chosen_filename =  sorted(l1)[-1][1][:-3]

    print ('Directory : ', directory)
    print ('Chosen Filename : ',chosen_filename)
    print()
    print ('Start : ', time.ctime())
    print()
    
    f_in = open(directory+chosen_filename+'.in')
    f_out = open(directory+chosen_filename+'.out', 'w')
    solve(f_in,f_out)
    f_in.close()
    f_out.close()

    print ()
    print ('End : ', time.ctime())


main_run()



#test_loop_speed()

