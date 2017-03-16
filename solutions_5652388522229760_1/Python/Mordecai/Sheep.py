#!usr/bin/python2

def sheep(N):
    if N == 0: return "INSOMNIA"
    digits = set()
    allD = {str(d) for d in range(10)}
    i = 0
    while True:
        i += 1
        for d in str(i*N):
            digits.add(d)
        if allD <= digits:
            return i*N

def main():
    cases = int(raw_input())
    for case in range(1, cases+1):
        print "Case #%i:" %case, sheep(int(raw_input()))

if __name__ == '__main__':
   main()
