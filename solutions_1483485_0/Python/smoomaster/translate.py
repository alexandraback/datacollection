
table = str.maketrans('ejpmyslckdxvnribtahwfougzq', 'ourlangeismpbtdhwyxfckjvqz')

def do_translate(f):
    num_entries = int(f.readline())
    for entry_no in range(num_entries):
        text = f.readline().strip()
        print('Case #%d: %s' % (entry_no+1, text.translate(table)))

    f.close()

import sys
do_translate(open(sys.argv[1]))
