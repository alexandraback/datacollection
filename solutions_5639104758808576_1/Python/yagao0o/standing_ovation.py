# author: yagoa0o
# date : 2015/04/11


class Solution():
    def get_result(self,input_file_name, output_file_name):
        infile = open(input_file_name)
        outfile = open(output_file_name,"w+")
        total = int(infile.readline())
        #main procedure
        for i in range(total):
            case_i_input = infile.readline()
            friends_need = 0
            s_max = int(case_i_input.split(' ')[0])
            current_ovation = 0
            s_i_input = case_i_input.split(' ')[1]
            for s_i in range(s_max + 1):
                if current_ovation + friends_need < s_i:
                    friends_need += 1
                current_ovation += int(s_i_input[s_i])
            outfile.write('Case #' + str(i + 1) + ': ' + str(friends_need) + '\n')
            print('Case #' + str(i + 1) + ': ' + str(friends_need))
        infile.close()
        outfile.close()

solu = Solution()
solu.get_result('A-large.in', 'A-large.out')