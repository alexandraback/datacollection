# author: yagoa0o
# date : 2015/05/03

class Solution():
    def get_result(self, input_file_name, output_file_name):
        infile = open(input_file_name)
        outfile = open(output_file_name, "w+")
        total = int(infile.readline())

        # main procedure
        for i in range(total):
            #deal
            input_line = infile.readline()
            r = int(input_line.split()[0])
            c = int(input_line.split()[1])
            w = int(input_line.split()[2])
            result = (c / w) * r + w # time to locate
            if c % w == 0:
                    result -= 1
            outfile.write('Case #' + str(i + 1) + ': ' + str(result) + '\n')
        infile.close()
        outfile.close()
        return False

solu = Solution()
file_name = 'A-small-attempt0'
solu.get_result(file_name + '.in', file_name + '.out')