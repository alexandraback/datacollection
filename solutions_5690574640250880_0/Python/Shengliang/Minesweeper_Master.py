def main():
    fin = file("C-small-attempt7.in","r")
    t = int(fin.readline())
    fout = file("C-small-attempt7.out", "w")
    for i in range(t):
        scanf = fin.readline().split()
        r = int(scanf[0])
        c = int(scanf[1])
        m = int(scanf[2])
        if (m == 0):
            matrix = ("."*c + '\n')*r
            output = "Case #" + str(i+1) + ":\n" + matrix[0:len(matrix) - 2] + "c\n";
            fout.write(output)
            continue
        if (m == r*c - 1):
            matrix = ("*"*c + '\n')*r
            output = "Case #" + str(i+1) + ":\n" + matrix[0:len(matrix) - 2] + "c\n";
            fout.write(output)
            continue
        w = min(r, c)
        l = max(r, c)
        line = m / w
        reminder = m - line*w
        if line == l:
            output = "Case #" + str(i + 1) + ":\n" + "Impossible\n"
            fout.write(output)
            continue
        if (line <= l - 2) and (reminder == 0):
            if r == l:
                matrix = ("*"*w + '\n') * line
                matrix = matrix + ("."*w + '\n') * (l - line)
            else:
                matrix = ("*"*line + "."*(l - line) + '\n') * w;
            output = "Case #" + str(i+1) + ":\n" + matrix[0:len(matrix) - 2] + "c\n";
            fout.write(output)
            continue
        if (r*c - m < 4):
            output = "Case #" + str(i + 1) + ":\n" + "Impossible\n"
            fout.write(output)
            continue
        if (line < l - 2) and (reminder < w - 1) and w >= 3:
            if r == l:
                matrix = ("*"*w + '\n') * line
                matrix = matrix + ("*"*reminder + "."*(w - reminder) + '\n') + ("."*w + '\n')*(l - line - 1)
            else:
                matrix = ("*"*(line + 1) + "."*(l - line - 1) + '\n') * reminder
                matrix = matrix + ("*"*line + "."*(l - line) + '\n') * (w - reminder);
            output = "Case #" + str(i+1) + ":\n" + matrix[0:len(matrix) - 2] + "c\n";
            fout.write(output)
            continue
        if (line < l - 3) and (reminder == w - 1) and w >= 3:
            if r == l:
                matrix = ("*"*w + '\n') * line
                matrix = matrix + "*"*(w - 2) + "..\n" + "*"*1 + "."*(w - 1) + '\n'
                matrix = matrix + ("."*w + '\n')*(l - line - 2)
            else:
                matrix = ("*"*(line + 2) + "."*(l - line - 2) + '\n')
                matrix = matrix + ("*"*(line + 1) + "."*(l - line - 1) + '\n') * (reminder - 2)
                matrix = matrix + ("*"*line + "."*(l - line) + '\n') * 2;
            output = "Case #" + str(i+1) + ":\n" + matrix[0:len(matrix) - 2] + "c\n";
            fout.write(output)
            continue

        flag = True
        got = False
        if reminder == 0:
            line = line - 1;

        while flag:
            print str(i+1) +"#   "  + str(line)

            leftline = l - line
            leftmine = m - line * w
            if leftline == 1 or leftmine == 1:
                line = line - 1
                continue
            print leftmine
            print leftline

            if ((leftmine % leftline == 0) & (leftmine / leftline <= w - 2)):
                flag = False
                got = True
                miemiemie = leftmine / leftline;
                if r == l:
                    matrix = ("*"*w + '\n') * line
                    matrix = matrix + ("*"*miemiemie + "."*(w - miemiemie) + '\n') * leftline
                else:
                    matrix = ("*"*l + '\n') * miemiemie
                    matrix = matrix + ("*"*line + "."*leftline + '\n') * (w - miemiemie);
                output = "Case #" + str(i+1) + ":\n" + matrix[0:len(matrix) - 2] + "c\n";
            else:
                if (leftmine % leftline == 1) & (leftmine / leftline < w - 3) & (leftline > 2):
                    flag = False
                    got = True
                    miemiemie = leftmine / leftline;
                    if r == l:
                        matrix = ("*"*w + '\n') * line
                        matrix = matrix + ("*"*(miemiemie + 1) + "."*(w - miemiemie - 1) + '\n');
                        matrix = matrix + ("*"*miemiemie + "."*(w - miemiemie) + '\n') * (leftline - 1)
                    else:
                        matrix = ("*"*l + '\n') * miemiemie
                        matrix = matrix + ("*"*(line+1) + "."*(leftline - 1) + '\n')
                        matrix = matrix + ("*"*line + "."*leftline + '\n') * (w - miemiemie - 1);
                    output = "Case #" + str(i+1) + ":\n" + matrix[0:len(matrix) - 2] + "c\n";
            line = line - 1;
            if (line <= l / 2):
                break
        if got:
            fout.write(output)
            continue

        output = "Case #" + str(i + 1) + ":\n" + "Impossible\n"
        fout.write(output)

if __name__ == '__main__':
    main()
