#==============================================================================
# IMPORTS
#==============================================================================
import sys

#==============================================================================
# CONSTANTS
#==============================================================================
EX_GOOGLE = \
    'ejp mysljylc kd kxveddknmc re jsicpdrysi' + \
    'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd' + \
    'de kr kd eoya kw aej tysr re ujdr lkgc jv'

EX_ENGLISH = \
    'our language is impossible to understand' + \
    'there are twenty six factorial possibilities' + \
    'so it is okay if you want to just give up'

GOOG_2_ENG = dict(zip([l for l in EX_GOOGLE], [l for l in EX_ENGLISH]))

# Add by hand:
GOOG_2_ENG['z'] = 'q'
GOOG_2_ENG['q'] = 'z'


#==============================================================================
# FUNCTIONS
#==============================================================================
def read_input_file (filename):
    fh = open(filename, 'r')
    tests = int(fh.readline())
    ret = fh.readlines()
    fh.close()
    return ret

def test ():
    letters = ' abcdefghijklmnopqrstuvwxyz'
    letters = [l for l in letters]
    googles = letters[:]

    keys = GOOG_2_ENG.keys()
    keys.sort()
    print letters
    print keys
    print letters == keys

    for letter in EX_ENGLISH:
        if letter in letters:
            letters.remove(letter)
    for letter in EX_GOOGLE:
        if letter in googles:
            googles.remove(letter)

    print 'engl:', letters
    print 'goog:', googles


def main (filename):
    for count, line in enumerate(read_input_file(filename)):
        line = ''.join([GOOG_2_ENG[l] for l in line[:-1]])
        print 'Case #%d: %s' % (count + 1, line)
        

#==============================================================================
# MAIN
#==============================================================================
if __name__ == '__main__':
    main(sys.argv[1])
