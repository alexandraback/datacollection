goog = {'\n': '', ' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'q': 'z', 'z': 'q'}

in_file = open("A-small-attempt0.in")

lines = in_file.readline()

for n in range(int(lines)):
    line_in = in_file.readline()
    line_length = len(line_in)
    line_out = ""
    for i in range(line_length):
        line_out += goog[line_in[i]]
    print "Case #%d: %s" % (n+1, line_out)
