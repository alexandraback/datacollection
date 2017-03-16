def min_levels(levels):
    """
    T = [[0 for i in range(2*len(levels))] for j in range(len(levels))]
    for j in range(len(levels)):
        if levels[j][1]==0:
            T[j][0] = (2, True, True)
        elif levels[j][0]==0:
            T[j][0] = (1, True, False)
        else:
            T[j][0] = (0, False, False)
    max_stars = max([T[j][0][0] for j in range(len(levels))])
    for j in range(2*len(levels)):
        for i in range(len(levels)):
            if T[i][j-1][2] == True:
                T[i][j] = T[i][j-1]
            elif levels[i][1]<=max_stars: 
                if T[i][j-1][1] == True:
                    T[i][j] = (max_stars+1, True, True)
                else:
                    T[i][j] = (max_stars+2, True, True)
            elif levels[i][0]<=max_stars:
                if T[i][j-1][1] == True:
                    T[i][j] = T[i][j-1]
                else:
                    T[i][j] = (max_stars+1, True, False)
            else:
                T[i][j] = (max_stars, False, False)
    """
    zero_stars = levels
    one_stars = []
    two_stars = []
    star_count = 0
    move_count = 0
    while zero_stars or one_stars:
        move = -1
        move_from = 0
        moved_to = 2
        max_two = 0
        for i, level in enumerate(zero_stars):
            if level[1]<=star_count:
                move = i
        if move==-1:#move from one to two
            for i, level in enumerate(one_stars):
                if level[1]<=star_count:
                    move = i
                    move_from = 1
        if move==-1:#move from zero to one
            for i, level in enumerate(zero_stars):
                if level[0]<=star_count and level[1]>=max_two:
                    move = i
                    moved_to = 1
                    max_two = level[1]
        if move==-1:
            return 'Too Bad'
        else:
            print 'star_count: ' + str(star_count)
            print 'move: ' + str(move)
            print 'move_from: ' + str(move_from)
            print 'move_to: ' + str(moved_to)
            print 'zero_stars: ' + str(zero_stars)
            print 'one_stars: ' + str(one_stars)
            if move_from==0:
                to_move = zero_stars[move]
                del zero_stars[move]
                if moved_to == 1: 
                    one_stars.append(to_move)
                    star_count+=1
                elif moved_to==2:
                    two_stars.append(to_move)
                    star_count+=2
            elif move_from==1:
                to_move = one_stars[move]
                del one_stars[move]
                two_stars.append(to_move)
                star_count+=1
            move_count+=1
    return move_count
    
input_file = open('B-small-attempt0.in')
output_file = open('output', 'w')
case_count = 1
current_count = 0
current_in = 0
length = 0
input_list = []
for i, line in enumerate(input_file.readlines()):
    if i==0 or i==1:
        continue
    else:
        if len(line.split())==1 and i!=1:
            print input_list
            length = int(line.split()[0])
            current_count = 0
            output_file.write('Case #%d: %s\n' % (case_count, min_levels(input_list)))
            input_list = []
            case_count+=1
        else:
            input_list.append(map(int, line.split()))
        #do something relevant
        #numbers = map(int, line.split())
        #count = single_case(numbers[0], numbers[1], numbers[2], numbers[3:])
        #output_file.write('Case #%d: %d\n' % (i, count))
output_file.write('Case #%d: %s\n' % (case_count, min_levels(input_list)))
input_file.close()
output_file.close()

            
print min_levels([(0,1),(0,2)])
print min_levels([(2,2),(0,0),(4,4)])
print min_levels([(1,1)])
print min_levels([(0,5),(0,1),(1,1),(4,7),(5,6)])

