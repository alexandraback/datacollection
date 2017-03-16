import codejam
import numpy

x_wins = ['XXXT', 'XXTX', 'XTXX', 'TXXX', 'XXXX']
o_wins = ['OOOT', 'OOTO', 'OTOO', 'TOOO', 'OOOO']

def check_line(lines, dot_found=False):
    for line in lines:
        line = ''.join(line)
        dot_found = ('.' in line) or dot_found
        if any(xwin in line for xwin in x_wins):
            return dot_found, "X won"

        elif any(owin in line for owin in o_wins):
            return dot_found, "O won"

    return dot_found, None


for case in xrange(codejam.readint()):
    lines = [list(codejam.readstring()) for l in xrange(4)]
    rotated = numpy.rot90(lines)

    # Check Horizontal
    dot_found, won = check_line(lines)

    if not won:
        dot_found, won = check_line(rotated, dot_found)

    if not won:
        dot_found, won = check_line([numpy.diagonal(lines)], dot_found)

    if not won:
        dot_found, won = check_line([numpy.diagonal(rotated)], dot_found)

    res = won or ("Game has not completed" if dot_found else "Draw")
    print "Case #%d: %s" % (case + 1, res)

    # Read empty line
    codejam.readstring()
