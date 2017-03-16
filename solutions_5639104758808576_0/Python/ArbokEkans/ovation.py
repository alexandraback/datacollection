
def main():
    T = int(input())
    
    for i in range(1,T+1):
        smax, seq = input().split()
        #smax = int(smax)
        seq = list(map(int,seq))
        res = solve(seq)
        print("Case #{}: {}".format(i, res))



def solve(seq):
    added = 0
    standing = 0
    for shyness, number in enumerate(seq):
        if number:
            if shyness > standing:
                added += shyness - standing
                standing += shyness - standing
            standing += number
    return added


main()
