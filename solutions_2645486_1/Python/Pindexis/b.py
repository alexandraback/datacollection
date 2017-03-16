import time
import sys
import pdb

infile = open("binput.txt")
outfile = open("boutput.txt", 'w')

timeit = 1
debugv = 1

def main():
        T = int(infile.readline())
        for case in range(1,T+1):
            doCase(case)
            


def solve(E,R,N,values):

    total = 0
    e = E
    for i,v in enumerate(values):
        if(i == N-1):
            total += e * v
            e = 0
            return total
        j = i + 1
        tempe= e + R
        while j < N and values[j] < v:
            j = j + 1
            tempe += R
        if( j == N  ):
            total += e * v
            e = 0
        else:
            diff = tempe - E
            if ( diff > 0):
                if(e-diff <0):
                    diff = e
                total += diff * v
                e = e - diff
                if(e < 0):
                    pdb.set_trace()
        i+=1
        e+=R        

            
        
            
def doCase(case):
    E,R,N = map(int, infile.readline().strip().split())
    values = map(int,infile.readline().strip().split())
    
    result = solve(E,R,N,values)
    debug("{}\n".format(result))
    outfile.write("Case #{}: {}\n".format(case, result))
    

def debug(m):
    if debugv:
        sys.stdout.write(m)

		
if __name__ == '__main__':  
    startTime = time.clock()
    main()
    if timeit:
        sys.stdout.write("Completed in {} seconds.\n".format(time.clock() - startTime))
    outfile.close()
