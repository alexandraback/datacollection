'''
Created on 2012/4/14

@author: bletchley
'''
import math

def rotate(x,A,B):
    #print x
    size = len("%d" % x)
    base = int(math.pow(10,size-1))
    #print size , base
    b=x
    count = 0;
    while True:
        b = (b%10)*base+(b/10)
        #print "rot",int(b)
        if b==x :
            break;
        if A<=b and b<B :
            count+=1
            #print x,b
    return count 
        
        
        
    
if __name__ == '__main__':
    file = open("b.in")
    outfile = open("b.out","w")
    num = int(file.readline())
    
    for index in range(1,num+1) :
        #str = "Case #%d: " % (x+1)
        line = file.readline().split(" ")
        pair = (int(line[0]),int(line[1])+1)
        #print pair
        count =0 
        for x in range(pair[0],pair[1]):
            count+=rotate(x,pair[0],pair[1])
        outfile.write("Case #%d: %d\n" % (index , count/2)) 
    pass