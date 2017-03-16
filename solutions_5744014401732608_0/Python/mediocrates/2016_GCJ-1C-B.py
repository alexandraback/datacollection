def solve(b, m):
    max_possible = 2**(b-2)
    if m > max_possible:
        return False, None

    # possible
    if b == 2:
        paths = ["01"]
    else:
        paths = [''.join(list(("0{0:0>%db}1" % (b-2)).format(m-1)))]
    for x in range(b-2):
        path = ''.join((x+2)*["0"] + (b-x-2)*["1"])
        paths.append(path)
    paths.append(b*"0")

    return True, '\n'.join(paths)


def main():
    input_filename = 'input.txt'
    output_filename = 'output.txt'
    open(output_filename, 'wb').close()
    with open(input_filename, 'r+b') as f:
        with open(output_filename, 'r+b') as g:
            t = int(f.readline().strip())
            for i in range(1, t+1):
                b, m = map(long, f.readline().strip().split())
                possible, solution = solve(b, m)
                if possible:
                    print "Case #%d: POSSIBLE" % i
                    print solution
                    g.write("Case #%d: POSSIBLE\n" % i)
                    # g.write("%d %d\n" % (b, m))
                    g.write(solution)
                    g.write("\n")
                else:
                    print "Case #%d: IMPOSSIBLE" % i
                    g.write("Case #%d: IMPOSSIBLE\n" % i)
                    # g.write("%d %d\n" % (b, m))

if __name__ == '__main__':
    main()
