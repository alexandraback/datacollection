from util import *

def main():
    r = reader("input")
    num = int(r.next())
    ans = []
    for i in range(num):
        line = r.next().split(" ")
        smax = int(line[0])
        people = map(int, line[1])

        count = 0
        extras = 0
        for shyness in range(smax + 1):
            if count >= shyness:
                count += people[shyness]
            else:
                extras += shyness - count
                count = shyness + people[shyness]
        ans.append(extras)

    write("output", ans)

if __name__ == '__main__':
    main()
