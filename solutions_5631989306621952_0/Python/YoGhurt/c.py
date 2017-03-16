import math

def is_prime(n):
    if n % 2 == 0 and n > 2:
        return False
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True

def solve(s, x, res):
    s = s.strip()
    result = ""
    for c in s:
        if len(result) == 0 or c >= result[0]:
            result = c + result
        else:
            result = result + c
    res.write("Case #{}: {}\n".format((x+1), result))

def main():
    f = open("C://CodeJam/a1.in", 'r')
    res = open("C://CodeJam/a1.out", 'w')
    T = int(f.readline())
    for x in range(T):
        s = f.readline()
        solve(s, x, res)
    f.close()
    res.close()

if __name__ == "__main__":
    main()
