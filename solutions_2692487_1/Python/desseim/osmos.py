import sys

CONST = 999999999

def min_op_rec(armin_mote, ordered_motes):
    if len(ordered_motes) < 1: return 0

    if armin_mote == 1:  #can't eat nothing
        return len(ordered_motes)  #remove all remainings

    if armin_mote > ordered_motes[0]:  #can eat next
        return min_op_rec(armin_mote + ordered_motes[0], ordered_motes[1:])
    else:  #can't eat next, either add or remove
        #if we add mote until we can continue:
        add_ops = 0
        while armin_mote <= ordered_motes[0]:
            armin_mote += armin_mote - 1
            add_ops += 1
        min_ops_with_add = add_ops + min_op_rec(armin_mote, ordered_motes)
        #if we remove
        min_ops_with_remove = len(ordered_motes)

        return min(min_ops_with_add, min_ops_with_remove)

def min_op(orig_armin_mote, orig_motes):
    return min_op_rec(orig_armin_mote, sorted(orig_motes))

def main(input_file_name, output_file_name):
    input_file = open(input_file_name, 'rU')
    output_file = open(output_file_name, 'w')
    for case in range(int(input_file.readline())):
        armin_mote, nb_motes = [int(x) for x in input_file.readline().split()]
        motes = [int(x) for x in input_file.readline().split()]
        min_ops = min_op(armin_mote, motes)
        print('case ' + str(case) + ': ' + str(min_ops))
        output_file.write('Case #' + str(case+1) + ': ' + str(min_ops) + '\n')
    input_file.close()
    output_file.close()


if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2])
