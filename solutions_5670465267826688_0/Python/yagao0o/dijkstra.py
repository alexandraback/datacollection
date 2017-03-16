# author: yagoa0o
# date : 2015/04/11

class Solution():
    multi_square = {'1': {'1': '1', 'i': 'i', 'j': 'j', 'k': 'k'},
                    'i': {'1': 'i', 'i': '-1', 'j': 'k', 'k': '-j'},
                    'j': {'1': 'j', 'i': '-k', 'j': '-1', 'k': 'i'},
                    'k': {'1': 'k', 'i': 'j', 'j': '-i', 'k': '-1'}}

    def get_result(self, input_file_name, output_file_name):
        infile = open(input_file_name)
        outfile = open(output_file_name, "w+")
        total = int(infile.readline())
        # main procedure

        for i in range(total):
            input_parms = infile.readline().split()
            l = int(input_parms[0])
            x = int(input_parms[1])
            characters = infile.readline()
            result = 'Yes'
            if x % 4 != 0 and l > 1:
                #count characters
                cal_result = '1'
                cal_string = characters[:l] * (x % 4 + 8) if x > 12 else characters[:l] * x
                got_i = False
                got_j = False
                for char in cal_string:
                    cal_result = self.multiply(cal_result, char)
                    if (not got_i) and cal_result == 'i':
                        got_i = True
                    if (not got_j) and got_i and cal_result == 'k':
                        got_j = True
                if cal_result == '-1' and got_i and got_j:
                    result = 'YES'
                else:
                    result = 'NO'
            else:
                result = 'NO'
            outfile.write('Case #' + str(i + 1) + ': ' + result + '\n')
        infile.close()
        outfile.close()
        return False

    def multiply(self, a, b):
        is_negative = False
        is_negative = is_negative != (a[0] == '-')
        is_negative = is_negative != (b[0] == '-')
        result = self.multi_square[a[-1]][b[-1]]
        is_negative = is_negative != (result[0] == '-')
        if not is_negative:
            return result[-1]
        else:
            return '-' + result[-1]


solu = Solution()
file_name = 'C-small-attempt2'
solu.get_result(file_name + '.in', file_name + '.out')
