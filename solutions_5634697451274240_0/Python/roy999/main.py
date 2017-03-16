
def process(input_file, out):
    t = int(input_file.readline())

    for i in range(1, t + 1):
        result = solve(input_file.readline().strip())
        out.write("Case #%i: %i\n" % (i, result))


def solve(state, offset=None, target="+"):
    if offset is None:
        offset = len(state)

    if offset == 0:
        return 0
    elif state[offset - 1] == target:
        return solve(state, offset - 1, target)
    else:
        return solve(state, offset - 1, state[offset - 1]) + 1
