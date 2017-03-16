def solve(f):
    a,b,k = map(int, f.readline().split("\n")[0].split())

    output = 0

    for i in range(a):
        for j in range(b):
            if i&j < k:
                output += 1
    return output
