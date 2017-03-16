def is_div_under20(n):
    if n%2 == 0: return 2
    if n%3 == 0: return 3
    if n%5 == 0: return 5
    if n%7 == 0: return 7
    if n%11 == 0: return 11
    if n%13 == 0: return 13
    if n%17 == 0: return 17
    if n%19 == 0: return 19
    return 0

print("Case #1:")
count = 0
for i in range(2147483649, 4294967295):
    if(count < 500):
        good = True
        if(i%2 != 0):
            b = int(str(bin(i))[2:])
            c = []
            for j in range(9):
                if good:
                    c.append(is_div_under20(int(str(b), base = j+2)))
                    if c[j] == 0:
                        good = False
            if good:
                print(b, end = " ")
                for z in range(len(c)):
                    print(c[z], end = " ")
                count += 1
                print()


