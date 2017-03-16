import sys

def main():
    num_cases = int(sys.stdin.readline())
    cases = [sys.stdin.readline().strip() for i in range(num_cases)]
    memo_dict = {}
    for i in range(num_cases):
        print("Case #"+str(i+1)+": "+str(solve(cases[i])))

def solve(case):
    K = int(case.split(' ')[2])
    return ' '.join([str(i+1) for i in range(int(K))])

if __name__=='__main__':
    main()
