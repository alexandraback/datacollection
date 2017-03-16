with open("A-large.in") as infile:
    with open("A-large.out", "w") as outfile:
        next(infile)

        for case, line in enumerate(infile, start=1):
            _, shyness = line.split()

            friends = 0
            standing = 0

            for n, digit in enumerate(shyness):
                digit = int(digit)

                while standing < n:
                    friends += 1
                    standing += 1


                standing += digit

            print("Case #{}: {}".format(case, friends), file=outfile)
