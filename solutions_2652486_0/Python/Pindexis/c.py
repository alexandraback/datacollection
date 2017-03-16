import time
import sys
import pdb

infile = open("cinput.txt")
outfile = open("coutput.txt", 'w')

timeit = 1
debugv = 1

def main():
        T = int(infile.readline())
        for case in range(1,T+1):
            doCase(case)
            


def solve(R,N,M,K,values):
    for number  in values:
        if(N == 1):
            for i in range(2,M+1):
                 if i*i*i == number:
                     return str(i)+str(i)+str(i)
        if(N == 2):            
            for i in range(2,M+1):
                for j in range(2,M+1):
                    if i*j*j == number:
                        return str(i)+str(j)+str(j)
        if(N == 3):                  
            for i in range(2,M+1):
                for j in range(2,M+1):
                    for h in range(2,M+1):
                        if i*j*h == number:
                            return str(i)+str(j)+str(h)
        if(N == 4):                  
            for i in range(2,M+1):
                for j in range(2,M+1):
                    for h in range(2,M+1):
                        for u in range(2,M+1):
                            if i*j*h*u == number:
                                return str(i)+str(j)+str(h)+str(u)                    
    return "none"                
            
        
            
def doCase(case):
    R,N,M,K = map(int, infile.readline().strip().split())
    outfile.write("Case #1:\n");
    for i in range(R):
        values = map(int,infile.readline().strip().split())
        result = solve(R,N,M,K,values)
        outfile.write(result+"\n")
    
    

def debug(m):
    if debugv:
        sys.stdout.write(m)

		
if __name__ == '__main__':  
    startTime = time.clock()
    main()
    if timeit:
        sys.stdout.write("Completed in {} seconds.\n".format(time.clock() - startTime))
    outfile.close()
