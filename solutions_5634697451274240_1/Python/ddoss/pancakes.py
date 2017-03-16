import sys

def main():
    num_cases = int(sys.stdin.readline())
    cases = [sys.stdin.readline().strip() for i in range(num_cases)]
    memo_dict = {}
    for i in range(num_cases):
        print("Case #"+str(i+1)+": "+str(solve(cases[i])))

def solve(case):
    num_inversions = 0
    if case=='':
        return 0

    sym=case[0]
    for i in range(len(case)):
        if not case[i]==sym:
            sym=case[i]
            num_inversions+=1
    if case[-1]=='-':
        num_inversions+=1
    return num_inversions



if __name__=='__main__':
    main()
