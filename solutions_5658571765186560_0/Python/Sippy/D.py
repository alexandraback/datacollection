def calc(file):
    x, r, c = map(int, file.readline().split())
    if x == 1: return "GABRIEL"
    elif x == 2:
        if (r*c)%2 == 1 : return "RICHARD"
        else: return "GABRIEL"
    elif x == 3:
        if (r*c)%6 == 0 or r*c == 9: return "GABRIEL"
        else: return "RICHARD"
    elif x == 4:
        if (r*c) >= 12: return "GABRIEL"
        else: return "RICHARD"

def main():
    file = open("input.txt")
    fl_o = open("output.txt", 'w')
    T = int(file.readline())
    for t in range(T):
        ans = calc(file)
        fl_o.write("Case #" + str(t+1) + ": " + str(ans) + "\n")
    fl_o.close()

main()