from pprint import pprint
inputfile = file("in", "rb")
outputfile = file("out", "wb")
out_s = "Case #%d: %s"
parse_line = lambda: [int(a) for a in inputfile.readline().split()]
rl = lambda: inputfile.readline().replace("\n","")

big_db_thing = {1: 1}
maxi = 10
def get_result(n):
    global maxi
    if n in big_db_thing:
        return big_db_thing[n]
    for i in xrange(maxi, n):
        get_result(i)
    maxi = n-1
    revn = int(str(n)[::-1]) 
    if revn < n and n%10 != 0:
        result = 1 + min(get_result(n-1), get_result(revn))
        big_db_thing[n] = result
        return result
    result = 1 + get_result(n-1)
    big_db_thing[n] = result
    return result

def do_case(ncase):
    n, = parse_line()
    print >>outputfile, out_s % (ncase, str(get_result(n)))
    #pprint(big_db_thing)



for i in xrange(10):
    big_db_thing[i+1] = i+1
T = int(inputfile.readline())
for ncase in xrange(1,T+1):
    do_case(ncase)
    