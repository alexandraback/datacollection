import sys


def solve(A, sizes):

    modifications = 0
    sizes.sort()
    mote = A

    for i, s in enumerate(sizes):
        if s < mote:
            mote = mote + s
        else:
            # need to modify problem

            if mote + mote-1 > s:
                # add a mote, and continue
                modifications += 1
                mote += mote-1 + s
            else:
                # motes we cant' reach:
                left = (len(sizes) - i)

                # can we solve by adding < left motes?
                adds = solve_by_adding_in_time(mote, sizes[i:])

                return modifications + min(adds, left)

    return modifications


def solve_by_adding_in_time(mote, sizes):
    attempts = 0
    size = 0
    while mote <= sizes[-1]:
        # can get the next mode
        if mote > sizes[size]:
            mote += sizes[size] 
            size += 1
        else:
            mote += mote-1
            attempts += 1

        if attempts >= len(sizes):
            break


    return attempts


if __name__ == '__main__':
    # usage: $ python blank.py input.txt > output.txt
    # in python shell: >>> import blank
    #                  >>> blank.solve()
    #                  >>> reload(blank)

    #preprocess()
    #var = raw_input("Done preprocessing. press enter when file ready>")

    # open file
    try:
        in_file = open(sys.argv[1], 'r')
    except:
        print "Error opening file"
        sys.exit()

    line = in_file.readline()
    total_cases = int(line)

    for i in range(total_cases):
        # parse
        A, N = map(int, in_file.readline().split(' '))
        sizes = map(int, in_file.readline().split(' '))
        # parse the rest of the input

        result = solve(A, sizes)

        print "Case #{}: {}".format(i+1, result)
