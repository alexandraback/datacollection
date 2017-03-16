f = open("C.in")
num = int(f.readline())
output = ""
for n in range(num):
    rows, cols, mines = [int(x) for x in f.readline().strip().split(" ")]
    output_val = None

    def flat_ar(ar):
        out = ""
        m = 0
        for k in ar:
            out += "\n"
            for j in k:
                out += j
                if j == "*":
                    m += 1
        print "Found mines", m, "Expected", mines
        if m != mines:
            print "ERROR MINES NOT EQUAL!!!!"
        return out

    if  (mines == 0):
        ar = []
        for k in range(rows):
            ar.append([])
            for j in range(cols):
                ar[k].append(".")
        ar[0][0] = "c"
        output_val = flat_ar(ar)

    elif (rows * cols) == mines + 1:
        ar = []
        for k in range(rows):
            ar.append([])
            for j in range(cols):
                ar[k].append("*")
        ar[0][0] = "c"
        output_val = flat_ar(ar)

    elif (rows == 2 or cols == 2):
        if rows * cols - mines == 2 or rows*cols - mines == 3:
            output_val = "\nImpossible"
        elif mines%2 == 1:
            output_val = "\nImpossible"
        else:
            ar = []
            for k in range(rows):
                ar.append([])
                for j in range(cols):
                    ar[k].append(".")
            ar[rows-1][cols-1] = "c"
            if rows > 1:
                ar[1][0] = "."
            else:
                ar[0][1] = "."
            for k in range(mines/2):
                if rows==2:
                    ar[0][k] = "*"
                    ar[1][k] = "*"
                else:
                    ar[k][0] = "*"
                    ar[k][1] = "*"
            if mines % 2 == 1:
                if rows==2:
                    ar[1][mines/2] = "*"
                else:
                    ar[mines/2][1] = "*"

            output_val = flat_ar(ar)


    elif (rows == 1 or cols == 1) and (rows * cols) - mines >= 2:
        ar = []
        for k in range(rows):
            ar.append([])
            for j in range(cols):
                ar[k].append("*")
        ar[0][0] = "c"
        if rows > 1:
            ar[1][0] = "."
        else:
            ar[0][1] = "."

        for k in range((rows*cols) - mines - 2):
            if cols == 1:
                ar[k+2][0] = "."
            if rows == 1:
                ar[0][k+2] = "."
        output_val = flat_ar(ar)

    elif (rows * cols) - mines >= 4:
        ar = []
        for k in range(rows):
            ar.append([])
            for j in range(cols):
                ar[k].append(".")
        ar[rows - 1][cols-1] = "c"
        on_shell = 0
        mines_left =  mines
        on_fill_row = 0
        on_fill_col = 0
        while(mines_left != 0):
            if (mines_left > cols) and on_fill_row <= rows-4:
                for i in range(cols):
                    ar[on_fill_row][i] = "*"
                on_fill_row += 1
                mines_left -= cols
                continue

            print mines_left, "inside loop mines", on_fill_row, rows-4,  on_fill_col, cols-4
            if (mines_left >= 3) and on_fill_col <= cols-4 and on_fill_row > rows-4:
                print "Getting here?, inside the loop?"
                for i in range(3):
                    ar[rows-i-1][on_fill_col] = "*"
                on_fill_col += 1
                mines_left -= 3
                continue
            break

        print mines_left, "mines first", on_fill_row
        if on_fill_row <= rows-4 and mines_left != 0:
            for i in range(mines_left):
                print on_fill_row, i, "index"
                ar[on_fill_row][on_fill_col+i] = "*"
            if mines_left == cols-1-on_fill_col:
                ar[on_fill_row][cols-2] = "."
                ar[on_fill_row + 1][on_fill_col] = "*"
            print "subbing rest"
            mines_left -= mines_left

        print mines_left, "mines decond", on_fill_row
        if on_fill_col <= cols-4 and mines_left != 0:
            if mines_left == 1:
                ar[on_fill_row][on_fill_col] = "*"
                mines_left -= 1

            for i in range(mines_left):
                ar[(rows-1-mines_left)+i][on_fill_col] = "*"
            if mines_left == 2:
                ar[(rows-1-mines_left)+1][on_fill_col] = "."
                ar[(rows-1-mines_left)+0][on_fill_col+1] = "*"
                print "INSIDE HERE?"
            print "subbing rest"
            mines_left -= mines_left
            
            print "has cols left"

        print mines_left, "MINESLEFT"
        #mines_left should be less than 3
        if mines_left == 0:
            output_val = flat_ar(ar)

        elif mines_left == 1:
            ar[rows-3][cols-3] = "*"
            output_val = flat_ar(ar)

        elif mines_left == 2:
            ar[rows-3][cols-3] = "*"
            ar[rows-3][cols-2] = "*"
            output_val = flat_ar(ar)
            if ar[rows-3][cols-4] == "*":
                output_val = "\nImpossible"
            if cols == 3 and rows - on_fill_row == 3:
                output_val = "\nImpossible"

        elif mines_left == 3:
            ar[rows-3][cols-1] = "*"
            ar[rows-3][cols-2] = "*"
            ar[rows-3][cols-3] = "*"
            output_val = flat_ar(ar)
        elif mines_left == 4:
            output_val = "\nImpossible"
        elif mines_left == 5:
            ar[rows-3][cols-1] = "*"
            ar[rows-3][cols-2] = "*"
            ar[rows-3][cols-3] = "*"
            ar[rows-2][cols-3] = "*"
            ar[rows-1][cols-3] = "*"
            output_val = flat_ar(ar)

    else:
        output_val = "\nImpossible"

    temp = "Case #"+str(n+1) + ":" + (output_val) + "\n"
    print temp,
    output += temp

f = open ("C.out", "w+")
f.write(output)
f.close()



