'''
Created on 2012-4-28

@author: zhiqiang
'''

def main(case):
    A,B,P = case
    S = [1 for i in range(A+1)]
    c = 1
    for i in range(1,A+1):
        c *= P[i-1]
        S[i] = c
    back = [S[A-k]*(2*k+1+B-A) + (1-S[A-k])*(2*k+1+B-A+B+1) for k in range(A+1)]
    can = 2 + B
    return min(can,min(back)) 

if __name__ == '__main__':
    with open('A-small-attempt0.in') as fin:
        T = int(fin.readline())
        for i in range(T):
            [A,B] = [int(k) for k in fin.readline().split()]
            P = [float(k) for k in fin.readline().split()]
            print('Case #{}:'.format(i+1),main((A,B,P)))