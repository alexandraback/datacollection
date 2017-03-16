import numpy

def diamonds(x,y,curx,cury,num,diamonds):
    if x>num*2 or x<num*2 or y>num*2:
        return 0.0
    else:
        return fall(x,y,curx,cury,num,diamonds)

def fall(curx,cury,num,diamonds,totalnum,offset):
    #print diamonds
    if num <= 0:
        #import pdb; pdb.set_trace()
        zeros = numpy.zeros([totalnum,totalnum])
        #print zeros
        for d in diamonds:
            zeros[d[0]+offset,d[1]] = 1.0
        return zeros


    while (cury > 0):
        cury-=1

        # move
        left = [curx-1,cury-1] in diamonds
        right = [curx+1,cury-1] in diamonds

        if left and right:
            #end
            diamonds.append([curx,cury])
            return fall(0,100,num-1,list(diamonds),totalnum,offset)
        elif left:
            curx += 1
        elif right:
            curx -= 1
        elif [curx,cury-2] in diamonds:
            # prob
            leftprob = fall(curx-1,cury,num,list(diamonds),totalnum,offset)
            rightprob = fall(curx+1,cury,num,list(diamonds),totalnum,offset)
            return .5*leftprob+.5*rightprob
   

    diamonds.append([curx,cury])
    return fall(0,10000,num-1,list(diamonds),totalnum,offset)


def gen(num):
    array = fall(0,10000,num,[],(num*2)+1,num)
    numpy.save('array/'+str(num),array)

def access(num,x,y):
    if x>num*2 or x<(-num*2) or y>num*2:
        return 0.0
    else:
        array = numpy.load('array/'+str(num)+'.npy')
        return array[x+num,y]

tests = int(raw_input())
i = 0
out = open('output.txt','w')

while i<tests:
    i+=1
    num,x,y=raw_input().strip().split()
    num = int(num)
    x = int(x)
    y = int(y)
    out.write("Case #"+str(i)+": "+str(access(num,x,y))+'\n')
    print ''

'''for i in range(20):
    gen(i+1)
    print i'''
#gen(21)
