def calc(file):
    d = int(file.readline())
    ps = map(int, file.readline().split())
    ks = [0]*1002
    for p in ps:
        ks[p] += 1
    start = 1000
    notPossible = False
    time = 0
    while True:
        if start <= 1: break
        elif ks[start] >= start/2:break
        if ks[start] == 0:
            start -= 1
            continue
        spend = 0
        for idx in range(start, 0, -1):
            if spend < start - idx:
                time = time + spend
                start = idx
                break
            if idx == 1:
                notPossible = True
            brk1 = idx/2
            brk2 = idx - brk1
            ks[brk1] += ks[idx]
            ks[brk2] += ks[idx]
            spend += ks[idx]
            ks[idx] = 0
        if notPossible: break
    return time + start

def main():
    file = open("input.txt")
    fl_o = open("output.txt", 'w')
    T = int(file.readline())
    for t in range(T):
        ans = calc(file)
        fl_o.write("Case #" + str(t+1) + ": " + str(ans) + "\n")
    fl_o.close()

main()