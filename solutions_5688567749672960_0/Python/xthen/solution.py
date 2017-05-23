def flip(num):
    return int(str(num)[::-1])

def count(n):
    if n <= 20:
        return n

    cnt = 11
    curr = 11

    while curr < n:
        if ((flip(curr) <= n) & (flip(curr+1) > n) | (flip(curr) > flip(curr+1))) & (flip(curr) > curr):
            curr = flip(curr)
            cnt += 1
        elif (str(curr)[-1] == '9') & (flip(curr) <= n) & (flip(curr) > curr):
            curr = flip(curr)
            cnt += 1
        else:
            curr += 1
            cnt += 1

    return cnt

with open('A-small-attempt1.in') as f:
    stuff = f.readlines()

case = 1

while case < len(stuff):
    print("Case #"+str(case)+": "+str(count(int(stuff[case]))))
    case += 1