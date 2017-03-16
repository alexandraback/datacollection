def count_flips(s):
    flips = 1 if s[-1] == "-" else 0
    s0 = s[0]
    for s1 in s[1:]:
        if s0 != s1:
            flips += 1
        s0 = s1
        
    return flips
    
def main():
    T = int(input())
    for t in range(1,T + 1):
        S = input()
        res = count_flips(S)
        printable_res = str(res)
        print("Case #%d: %s" % (t, printable_res))
    
if __name__ == "__main__":
    main()