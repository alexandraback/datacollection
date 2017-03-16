import string
from mapping import mapping

if __name__ == '__main__':
    # prepare tranlation table
    frm = []
    to = []
    for from_char, to_char in mapping.iteritems():
        frm.append(to_char)
        to.append(from_char)
    table = string.maketrans(''.join(frm), ''.join(to))

    with open('A-small-attempt2.in') as input_file:
        cases_num = int(input_file.next())

        with open('A-small-0.out', 'w') as output_file:
            for i in range(cases_num):
                encoded = input_file.next()
                original = string.translate(encoded, table)
                output_file.write("Case #%s: %s" % (i+1, original))
