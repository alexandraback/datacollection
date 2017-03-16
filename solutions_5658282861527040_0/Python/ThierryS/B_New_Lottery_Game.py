import sys

def main():

    T = int(sys.stdin.readline())
    
    for case in range(1,T+1):
        A, B, K = map(int,(sys.stdin.readline()).split()) 
        #print A,B,K
        possible_ticket = []
        count = 0
        for i in range(A):
            for j in range(B):
                #print i, j
                if (i & j) < K:
                    count += 1
        print 'Case #%d: %d' %(case, count)
        
main()
        
