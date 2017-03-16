print("ok")

#input_filename = "A-test.txt"
#output_filename = "A-test-out.txt"

#input_filename = "A-small-attempt0.in"
#output_filename = "A-small-attempt0.out"

input_filename = "A-large.in"
output_filename = "A-large.out"


def solve(xs):
    friends = 0
    stands = 0
    for need, new_people in enumerate(xs):
        #print("Stands %d, need %d" % (stands, need))
        new_friends = need - stands if stands < need else 0
        stands += new_people + new_friends
        friends += new_friends
        #print("New people %d, new friends %d" % (new_people, new_friends))
    return friends


with open(input_filename, "r") as ifile:
    with open(output_filename, "w") as ofile:
        T = int(ifile.readline())
        for case in range(1, T+1):
            data = ifile.readline().split()[1]
            data = [int(s) for s in data]

            print("\nCase %d" % case)
            print("Task: %s" % str(data))

            result = solve(data)

            ofile.write("Case #%d: %d\n" % (case, result))
            print("Solve: %d" % result)


