import sys

def no_match(a, b):
    for i in range(len(a)):
        if b[i] == '?':
            continue;
        if a[i] != b[i]:
            return True
    return False

if __name__ == "__main__":
    fin = open(sys.argv[1])
    lines = fin.readlines()
    ca = int(lines[0])
    case = 1;

    for l in lines[1:]:
        a = 100000
        c = 0
        data = l.split(' ')
        length = len(data[0])
        if length == 1: sum = 10
        elif length == 2: sum = 100
        elif length == 3: sum = 1000
        for i in range(sum):
            if no_match(str(i).zfill(length), data[0]):
                continue
            for j in range(sum):
                if no_match(str(j).zfill(length), data[1]):
                    continue
                if abs(a-c) <= abs(i-j):
                    continue
                a = i;
                c = j;
        print "Case #"+str(case)+": " + str(a).zfill(length) + " " + str(c).zfill(length)
        case += 1



