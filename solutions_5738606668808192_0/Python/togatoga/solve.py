import sys
def nontrivial_divisor(number):
    for i in range(2, number):
        if (i * i > number):
            break
        if (number % i == 0):
            return i
    return -1
def decode_jamcoin(jamcoin, base):
    return int(jamcoin, base)

def solve():
    T = int(input())
    N,J = map(int, input().split())
    ans = []

    for bit in range(1 << N):
        jamcoin = ""
        for i in range(N):
            jamcoin += str(bit % 2)
            bit >>= 1
        if (not (jamcoin[0] == '1' and jamcoin[-1] == '1')):
            continue
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
        sys.stderr.write(str(len(ans)) + "\n")
        if (len(ans) >= J):
            break
    print ("Case #1:")
    for i in range(len(ans)):
        print (ans[i][0], " ".join(map(str, ans[i][1])))
if __name__ == "__main__":
    solve()
