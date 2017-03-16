input_file = open("bull.in", "r")
output_file = open("bull.out", "w")

def check(r, t, k) :
    return k * (2 * r - 1 + 2 * k) <= t

def search(r, t):
    l = 1
    h = 10000000000000
    while (l < h):
        mid = (l + h + 1) // 2
        if check(r, t, mid):
            l = mid
        else:
            h = mid - 1
    return l

T = int(input_file.readline())

for i in range(1, T+1):
    (r, t) = input_file.readline().split()
    r = int(r)
    t = int(t)
    ans = search(r, t)
    output_file.write("Case #" +str(i)+": "+str(ans)+"\n")

input_file.close()
output_file.close()
