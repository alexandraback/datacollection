print("Case #1:")
n = 32
j = 500
matrix = [0]*((n-4)//2)
for i in range(j):
    print("".join(["11" if el == 1 else "00" for el in [1]+matrix+[1]]), *[el + 1 for el in range(2, 11)])
    k = 0
    while matrix[k] == 1:
        matrix[k] = 0
        k += 1
    matrix[k] = 1
