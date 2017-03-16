import sys
import time
def nontrivial_divisor(number):
    if (number % 2 == 0):
        return 2
    if (number % 3 == 0):
        return 3
    return -1
def decode_jamcoin(jamcoin, base):
    return int(jamcoin, base)

def solve():
    T = int(input())
    N,J = map(int, input().split())
    ans = []

    for bit in range(1 << (N - 2)):

        jamcoin = str(format(bit, "b"))
        #print (jamcoin)
        while (len(jamcoin) < N - 2):
            jamcoin = "0" + jamcoin
        jamcoin = "1" + jamcoin
        jamcoin = jamcoin + "1"
        #print (bit, jamcoin)
        ok = True
        numbers = []

        for base in range(2, 11):
            number = decode_jamcoin(jamcoin, base)
            flag = nontrivial_divisor(number)
            if (flag == -1):
                ok = False
                break
            numbers.append(flag)
        if (not ok):
            continue

        ans.append([jamcoin, numbers])
        if (len(ans) >= J):
            break
        sys.stderr.write(str(len(ans)) + "\n")
    print ("Case #1:")
    for i in range(len(ans)):
        print (ans[i][0], " ".join(map(str, ans[i][1])))
if __name__ == "__main__":
    solve()
