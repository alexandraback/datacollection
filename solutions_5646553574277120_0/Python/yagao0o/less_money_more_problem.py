# author: yagoa0o
# date : 2015/05/10

class Solution():
    def get_result(self, input_file_name, output_file_name):
        infile = open(input_file_name)
        outfile = open(output_file_name, "w+")
        total = int(infile.readline())
        # main procedure
        for i in range(total):
            #deal
            input_line = infile.readline()
            c = int(input_line.split()[0])
            d = int(input_line.split()[1])
            v = int(input_line.split()[2])
            current_denomination = infile.readline().split()
            result = 0
            denomination_in_use_total = 0
            flag = 0
            next_current_denomination = int(current_denomination[flag])
            while denomination_in_use_total * c < v:
                #add a denomination
                if next_current_denomination and next_current_denomination <= denomination_in_use_total * c + 1:
                    #use old denomination
                    denomination_in_use_total += next_current_denomination
                    flag += 1
                    if flag < d:
                        next_current_denomination = int(current_denomination[flag])
                    else:
                        next_current_denomination = None
                else:
                    #add a new denomination
                    result += 1
                    denomination_in_use_total += denomination_in_use_total * c + 1
            outfile.write('Case #' + str(i + 1) + ': ' + str(result) + '\n')
        infile.close()
        outfile.close()
        return False

solu = Solution()
file_name = 'C-small-attempt0'
solu.get_result(file_name + '.in', file_name + '.out')