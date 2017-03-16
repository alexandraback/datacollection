def fac(n):
    ans = 1
    for i in range(1, n + 1):
        ans *= i
    return ans

def cnk(k, n):
    return fac(n) // fac(k) // fac(n - k)

def calc1(n, diag, y):
    print(n, diag, y)
    ans = 0
    nans = 0
    y += 1
    for i in range(0, diag):
        if n - i >= diag:
            continue
        if n - i < 0:
            continue
        if i >= y:
            ans += cnk(i, n)
        else:
            nans += cnk(i, n)
    return ans/(ans + nans)

    
def calc(n, diag, y, l, r):
    if l >= diag:
        return [0, 0]
    if r >= diag:
        return [0,0]
    if n == 0:
        if l >= y + 1:
            return [1, 0]
        else:
            return [0, 1]
    else:
        t = calc(n - 1, diag, y, l +1, r)
        u = calc(n - 1, diag, y, l , r + 1)
        u[0] += t[0]
        u[1] += t[1]
        return u
        
def main():
    input = open("B-small-attempt3.in", 'r')
    output = open("output.txt", 'w')
    a = input.readlines()
    for i in range (1, len(a)):
        n = int(a[i].split(' ')[0])
        x = int(a[i].split(' ')[1])
        y = int(a[i].split(' ')[2])
        print("!", n, x, y)
        if x < 0:
            x = -x
        c = (x + y) // 2
        if (n == 1):
            if x == 0 and y == 0:
                output.write("Case #" + str(i) + ": " + "1.0\n")
                continue
            else:
                output.write("Case #" + str(i) + ": " + "0.0\n")
                continue
        all = 0
        add = 1
        for q in range(0, c):
            all += add
            add += 4
        n = n - all
        if n < 0:
            output.write("Case #" + str(i) + ": " + "0.0\n")
            continue
        if n >= add:
            output.write("Case #" + str(i) + ": " + "1.0\n")
            continue
        
        diag = (add  - 1) // 2 + 1
        qwe = 0
        rty = 0
        anss = calc(n, diag, y, 0, 0)
        ans = anss[0] / (anss[0] + anss[1])
        output.write("Case #" + str(i) + ": " + str(ans)+ "\n")
        
if __name__ == '__main__':
    main()