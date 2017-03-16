from sys import stdin, stdout

digits = []

def init():
    global digits
    
    digits.append(0)
    for i in range(1, 10000006):
        digits.append(digits[i//10] | (1 << (i%10)))

def solve(test_id):
    global digits
    print("Case #{}: ".format(test_id), end='')

    n = int(stdin.readline().strip())

    if n == 0:
        print("INSOMNIA")
        return

    x = 0
    i = 1
    try:
        while True:
            x |= digits[i*n];
            if x == 0x3ff:
                break
            i += 1
    except:
        print("INSOMNIA")
        return

    print("{}".format(i*n))

def main():
    init()
    t = int(stdin.readline())
    for i in range(t):
        solve(i+1)

main()
