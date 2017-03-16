import sys

def print_outfits(outfits):
  return '\n'.join([' '.join([str(x) for x in day]) for day in outfits])


def solve_test(inp):
    #J, P, S, K = map(int, inp.readline().split())
    return ''

def solve_dumb(inp):
    J, P, S, K = map(int, inp.readline().split())
    print(J, P, S, K)
    if K == 1:
      ans = J * P
      outfits = [(j+1, p+1, 1 + (j+p) % S) for j in range(J) for p in range(P)]
    elif K >= S:
      ans = J * P * S
      outfits = [(j+1, p+1, s+1) for j in range(J) for p in range(P) for s in range(S)]
    elif K == 2:
      
      outfits = [(j+1, p+1, s+1) for j in range(J) for p in range(P) for s in range(S) if (j + p + s) % 3 != 0]
      ans = len(outfits) 
    return str(ans) +'\n' + print_outfits(outfits)
  

inp = open(sys.argv[1])
inp_dumb = open(sys.argv[1])
#out = open(sys.argv[1].rsplit('.',1)[0]+'.out', 'w')
out_dumb = open(sys.argv[1].rsplit('.',1)[0]+'.dumb.out', 'w')
n_tests = int(inp.readline())
inp_dumb.readline()
for i in range(n_tests):
    ans = solve_test(inp)
#    print("Case #%d: " % (i+1) + ans, file=out)

#
    ans_dumb = solve_dumb(inp_dumb)
    print("Case #%d: " % (i+1) + ans_dumb, file=out_dumb)

    if ans != ans_dumb:
      print('Wrong', i+1, file=sys.stderr)
#
#out.close()