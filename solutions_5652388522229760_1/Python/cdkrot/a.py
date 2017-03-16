#!/usr/bin/python3

def main():
    n = int(input())
    
    for i in range(n):
        k = int(input())
        if (k == 0):
            print("Case #{}: INSOMNIA".format(i + 1))
        else:
            cur = k
            seen = [False] * 10
            cnt = 0
            while True:
                val = cur
                while val != 0:
                    if seen[val % 10] == False:
                        seen[val % 10] = True
                        cnt += 1
                    val //= 10
                
                if cnt == 10:
                    break
                cur += k                
            print("Case #{}: {}".format(i + 1, cur))
main()
