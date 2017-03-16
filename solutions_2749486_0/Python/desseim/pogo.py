import sys

RES_FLOAT_STR_FORMAT = "{:.6f}"

X_MOVE_1_SEQ = "WE"
Y_MOVE_1_SEQ = "SN"

def go_to(cur_ind, target_ind, cur_move_len, move_seq):
#    import pdb; pdb.set_trace()
    target_delta = target_ind - cur_ind
    res_seq = ""
    while target_delta > cur_move_len:
        res_seq += move_seq[1]
        cur_ind += cur_move_len
        cur_move_len += 1
        target_delta = target_ind - cur_ind
    if target_delta == cur_move_len: res_seq += move_seq[1]
    elif target_delta < cur_move_len:
        res_seq += move_seq * target_delta

    return res_seq

def pogo_to(target_point):
    horiz_first = abs(target_point[0]) <= abs(target_point[1])
    cur_move_len = 1
    seq = ""
    if horiz_first:
        move_seq = X_MOVE_1_SEQ if target_point[0] > 0 else X_MOVE_1_SEQ[::-1]
        target_ind = abs(target_point[0])
        seq = go_to(0, target_ind, cur_move_len, move_seq)
        cur_move_len = 1 + len(seq)
        move_seq = Y_MOVE_1_SEQ if target_point[1] > 0 else Y_MOVE_1_SEQ[::-1]
        target_ind = abs(target_point[1])
        seq += go_to(0, target_ind, cur_move_len, move_seq)
    else:  #vert_first
        move_seq = Y_MOVE_1_SEQ if target_point[1] > 0 else Y_MOVE_1_SEQ[::-1]
        target_ind = abs(target_point[1])
        seq = go_to(0, target_ind, cur_move_len, move_seq)
        cur_move_len = 1 + len(seq)
        move_seq = X_MOVE_1_SEQ if target_point[0] > 0 else X_MOVE_1_SEQ[::-1]
        target_ind = abs(target_point[0])
        seq += go_to(0, target_ind, cur_move_len, move_seq)
    return seq


def main(input_file_name, output_file_name):
    input_file = open(input_file_name, 'rU')
    output_file = open(output_file_name, 'w')
    for case in range(int(input_file.readline())):
        x, y = [int(x) for x in input_file.readline().split()]
        seq = pogo_to((x, y))
        output_file.write('Case #' + str(case+1) + ': ' + seq + '\n')
    input_file.close()
    output_file.close()


if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2])
