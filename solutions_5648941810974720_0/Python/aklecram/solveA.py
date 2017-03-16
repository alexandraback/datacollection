import sys
from multiprocessing import Pool

# Add git repository with helpers to path
# The repo is publicly available at git@github.com:marcelka/cocoli.git
sys.path.append("/home/marcelka/projects/cocoli/")

def run(pool=None): # {{{
    inp=sys.argv[1]
    outp="%s.out" % inp.split(".")[0]

    with open(inp, 'r') as _file, open(outp, 'w') as out:
        _cases = int(_file.readline())
        arguments = []
        for _case in range(_cases):
            string = _file.readline()[:-1]
            arguments.append((_case + 1, (string,)))

        if pool == None:
            results = list(map(solve_wrapper, arguments))
        else:
            results = sorted(
                list(pool.imap_unordered(solve_wrapper, arguments)),
                key=lambda r: r[0])
        
        for _case, result in results:
            out.write("Case #%s: %s\n" % (_case, result))

def solve_wrapper(args):
    case_no, _args = args
    print("Solving case #%s" %(case_no))
    return (case_no, solve(*_args))
# }}}

def digit(letters):
    def has(l):
        return l in letters and letters[l] > 0
    if has("Z"): return ("0", "ZERO")
    if has("W"): return ("2", "TWO")
    if has("G"): return ("8", "EIGHT")
    if has("X"): return ("6", "SIX")
    if has("H"): return ("3", "THREE")
    if has("S"): return ("7", "SEVEN")
    if has("R"): return ("4", "FOUR")
    if has("F"): return ("5", "FIVE")
    if has("O"): return ("1", "ONE")
    if has("N"): return ("9", "NINE")
    return (None, None)

def solve(string):
    letters = {}
    for letter in string:
        if letter not in letters:
            letters[letter] = 0
        letters[letter] += 1
    digits = []
    while True:
        d, ds = digit(letters)
        if d == None:
            return "".join(sorted(digits))
        for letter in ds:
            letters[letter] -= 1
        digits.append(d)

run()
#run(Pool(4))
