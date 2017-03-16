import sys

def main():
    num_cases = int(sys.stdin.readline())
    cases = [sys.stdin.readline().strip() for i in range(num_cases)]
    memo_dict = {}
    for i in range(num_cases):
        print("Case #"+str(i+1)+": "+str(solve(cases[i])))

def solve(case):
    K,C,S = case.split(' ')
    K,C,S = int(K),int(C),int(S)
    if C*S<K:
        return 'IMPOSSIBLE'
    else:
        i = 0
        soln = ''
        while i<K:
            choice = 1
            for j in range(C):
                i = min(i, K-1)
                choice += i*(K**(C-j-1))
                i+=1

            soln+=str(choice)+' '
        return soln

if __name__=='__main__':
    main()
