import sys
from math import pi

def solve(data):
    [w, n] = data.pop(0).strip().split(" ")
    n = int(n)
    l = len(w)
    total = 0
    for i in range(0, l+1):
        for j in range(i+1,l+1):
            if j - i < n:
                continue
            current = 0
            #print w[i:j]
            for letter in w[i:j]:
                if letter not in "aeiou":
                    current += 1
                else:
                    current = 0
                if current == n:
                    total += 1
                    current = 0
                    break

    return total

def main():
    data = sys.stdin.readlines()
    T = int(data.pop(0).strip())
    for i in range(1,T+1):
	res = solve(data)
        print("Case #%d: %d" % (i, res))

if __name__ == '__main__':
    main()
