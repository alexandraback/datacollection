def get_digits(num):
    return set([int(s) for s in str(num)])    
        
def count_sheeps(num):
    if num == 0:
        return -1
    
    digits_shown = [False] * 10
    k = 0
    while not all(digits_shown):
        k += 1
        digits = get_digits(k * num)
        for digit in digits:
            digits_shown[digit] = True
        
    return k * num
    
def main():
    T = int(input())
    for t in range(1,T + 1):
        N = int(input())
        res = count_sheeps(N)
        printable_res = "INSOMNIA" if res < 0 else str(res)
        print("Case #%d: %s" % (t, printable_res))
    
if __name__ == "__main__":
    main()