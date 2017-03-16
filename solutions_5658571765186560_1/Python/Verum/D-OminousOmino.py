#input_filename = "D-test.txt"
#output_filename = "D-test-out.txt"

#input_filename = "D-small-attempt0.in"
#output_filename = "D-small-attempt0.out"

input_filename = "D-large.in"
output_filename = "D-large.out"


def solve(x,r,c):
    r, c = min(r,c), max(r,c)
    if (r*c) % x != 0:
        return False
    elif x == 3 and r < 2:
        return False
    elif x == 4 and r < 3:
        return False
    elif x == 5 and r < 3:
        return False
    elif x == 5 and r == 3 and c < 10:
        return False
    elif x == 6 and r < 4:
        return False
    elif x > 6:
        return False
    else:
        return True


with open(input_filename, "r") as ifile:
    with open(output_filename, "w") as ofile:
        T = int(ifile.readline())
        for case in range(1, T+1):
            x, r, c = map(int, ifile.readline().split())

            print("\nCase %d" % case)
            print("Task: %s" % str( (x,r,c) ))

            result = solve(x,r,c)
            result = "GABRIEL" if result else "RICHARD"

            ofile.write("Case #%d: %s\n" % (case, result))
            print("Solve: %s" % result)
