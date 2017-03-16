import sys
import math

def sign(p):
    if p< 0:
        return -1
    elif p>0:
        return 1
    else:
        return 0

def solver(string):
    
        
    return 0

if __name__ == "__main__":
    fid = sys.stdin
    if len(sys.argv) >= 2:
        fname = sys.argv[1]
        if fname != '-':
            fid = open(fname)
            output = open('A_TEST.out','w')
    T = int(fid.readline().strip())#the number for test cases
    #some settings code
    
    
    for _t in xrange(T):
        r,t = map(long, fid.readline().strip().split(' '))
        ans = int(2*t/((2*r-1)+math.sqrt((2*r-1)*(2*r-1)+8*t)))
        output.write("Case #%d: %d\n" % (_t+1,ans))
        

fid.close()
output.close()
