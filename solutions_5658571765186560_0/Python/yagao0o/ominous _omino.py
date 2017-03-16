# author: yagoa0o
# date : 2015/04/11

class Solution():
    def get_result(self, input_file_name, output_file_name):
        infile = open(input_file_name)
        outfile = open(output_file_name, "w+")
        total = int(infile.readline())
        # main procedure
        for i in range(total):
            input_parms = infile.readline().split()
            x = int(input_parms[0])
            r = int(input_parms[1])
            c = int(input_parms[2])
            if r < c:
                r, c = c, r
            if x >= 7 or (r * c) % x != 0:
                result = 'Richard'
            elif x <= 2:
                result = 'Gabriel'
            elif x == 3:
                if c == 1:
                    result = 'Richard'
                else:
                    result = 'Gabriel'
            elif x == 4:
                if c <= 2:
                    result = 'Richard'
                else:
                    result = 'Gabriel'
            outfile.write('Case #' + str(i + 1) + ': ' + result + '\n')
        infile.close()
        outfile.close()
        return False

solu = Solution()
file_name = 'D-small-attempt1'
solu.get_result(file_name + '.in', file_name + '.out')

