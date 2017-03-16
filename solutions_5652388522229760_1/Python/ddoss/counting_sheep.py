import sys

def main():
    num_cases = int(sys.stdin.readline())
    cases = [int(sys.stdin.readline()) for i in range(num_cases)]
    for i in range(num_cases):
        print("Case #"+str(i+1)+": "+str(solve(cases[i])))

def solve(num):
    if num==0:
        return "INSOMNIA"
    else:
        digits = set([str(i) for i in range(10)])
        digits = digits.difference(set([char for char in str(num)]))
        return_num = num
        while len(digits)>0:
            return_num+=num
            digits = digits.difference(set([char for char in str(return_num)]))
        return return_num

if __name__=='__main__':
    main()
