def solve(n, j):
    largest = 2**(n-2)
    i = 0
    while i < largest and j > 0:
        output = [0]*10
        base2 = 2*(i + largest) + 1
        output[1] = str(find_factor(base2))
        if output[1] != '0':
            output[0] = str(bin(base2))[2:]
            base = 3
            flag = True
            while base < 11 and flag:
                factor = find_factor(int(output[0], base))
                if factor:
                    output[base-1] = str(factor)
                    base += 1
                else:
                    flag = False
            if base == 11:
                j -= 1
                print(' '.join(output))
        i += 1

def find_factor(n):
    for i in range(2, 12): #int(n**0.5) + 1):
        if n % i == 0:
            return i
    return 0

solve(32, 500)
