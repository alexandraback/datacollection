with open("A-small-attempt0.in") as infile:
    with open("A.out", "w") as outfile:
        next(infile)

        for case, line in enumerate(infile, start=1):
            line = line.rstrip()
            output = ""
            prefix = []
            suffix = []

            while line:
                c = max(line)
                i = line.rindex(c)
                prefix.append(c)
                suffix = [line[i+1:]] + suffix
                line = line[:i]

            print("Case #{}: {}".format(case, "".join(prefix + suffix)), file=outfile)
