def calc(file):
    n, s = file.readline().split()
    n = int(n)
    s = map(int, list(s))
    clapping = 0
    friends = 0
    for i in range(n+1):
        if i > clapping:
            extra = i - clapping
            friends += extra
            clapping += extra
        clapping += s[i]
    return friends

def main():
    file = open("input.txt")
    fl_o = open("output.txt", 'w')
    T = int(file.readline())
    for t in range(T):
        ans = calc(file)
        fl_o.write("Case #" + str(t+1) + ": " + str(ans) + "\n")
    fl_o.close()

main()