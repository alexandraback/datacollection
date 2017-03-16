#! python3

from collections import deque

def main():
    with open("A-large.in") as in_file:
        with open("A-large.out", "w") as fout:
            cases = int(in_file.readline())
            for x in range(cases):
                line = in_file.readline().replace('\n', '')
                win = deque(line[0])
                word = line[1:]
                
                for c in word:
                    if c >= win[0]:
                        win.appendleft(c)
                    else:
                        win.append(c)

                fout.write("Case #{0}: {1}\n".format(x + 1, "".join(list(win))))

if __name__ == "__main__":
    main()
