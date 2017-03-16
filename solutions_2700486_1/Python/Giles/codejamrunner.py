 
import networkx as nx
import graphing
 
class CodeJamRunner(object):

    def run(self, data_builder, solver, problem_name='A',problem_size='test'):
        """ Method that runs a code jam solver against a sample problem set.

        NOTE - This method needs a bit of refactoring, so that it is easier
        to override if there are any unusually structured problems that need
        a slightly different approach for example if you wanted to use a
        sub class of FileHelper.

        """
        self.get_case_data = data_builder
        self.solve_case = solver
        
        with open('%s-%s.in' % (problem_name,problem_size)) as f:
            case_count = int(f.readline())
            case =0
            results = []
            while case<case_count:
                data = self.get_case_data(FileHelper(f))
                results.append(self.solve_case(data))
                print results[-1]
                case += 1

        with open('%s-%s.out' %
                           (problem_name,
                            problem_size), 'w') as output:
             for i, result in enumerate(results):
                 output.write('Case #%s: %s\n' % (i+1, result))

        if problem_size == 'test':
            with open('%s-%s.out' % (problem_name, problem_size)) as output:
               with open('%s-%s.test-out' % (problem_name, problem_size)) as test:
                   for line in output.readlines():
                       check_line = test.readline().strip()
                       if not check_line == line.strip():
                           print 'expected ' +check_line
                           print 'generated '+ line
                           assert check_line == line
                    

class FileHelper(object):

    def __init__(self, f):

        self.f = f

    def readline(self):
        return self.f.readline().strip()

    def get_int(self):
        return int(self.readline())

    def get_ints(self):
        return [int(x) for x in self.readline().split(' ')]

    def get_float(self):
        return float(self.readline())

    def get_floats(self):
        return [float(x) for x in self.readline().split(' ')]

    def get_grid(self, rows):
        grid=[]

        for row in range(rows):
            grid.append(self.get_ints())

        return grid
    
    def get_float_grid(self, rows):
        grid=[]

        for row in range(rows):
            grid.append(self.get_floats())

        return grid

    def get_grid_graph(self, rows, cols=None):
        """reads and builds a 2d graph from input data. Each node is linked
        to the appropriate adjacent nodes (at right angles, not diagonals).

        cols is an optional parameter. If it is not passed in, then the
        number of items in the first row is used as the number of columns.

        """

        data = self.get_grid(rows)
        
        if not cols:
            cols = len(data[0])
            
        g = nx.grid_2d_graph(rows, cols)
        graphing.populate_graph(g, data)

        return g

def test():

    # Test the file helper
    with open('filehelper.test') as f:
        fh = FileHelper(f)
        
        assert fh.get_int() == 456
        
        test_ints = fh.get_ints()
        assert len(test_ints) == 5
        assert test_ints[3] == 32
                
        assert fh.get_float() == 6.667
        
        test_floats = fh.get_floats()
        assert  len(test_floats) == 3
        assert test_floats[2] == 3.14
        
        assert fh.readline() == 'hello world'

        grid = fh.get_grid(3)
        assert len(grid) == 3
        assert len(grid[0]) == 4
        assert grid[0][3] == 23
        assert grid[2][3] == 3
        assert grid[2][0] == 9
        assert grid[0][0] == 1

        graph = fh.get_grid_graph(3)
        assert len(graph.nodes()) == 12
        assert graph.node[(0,3)]['info'] == 23
        assert graph.node[(2,3)]['info'] == 3
        assert graph.node[(2,0)]['info'] == 9
        assert graph.node[(0,0)]['info'] == 1
        

    # Test the runner
    # Just copy the data from input to output and check each case is there.
    cjr = CodeJamRunner()
    cjr.run(lambda b: b.readline(), lambda a: a, 'runner', 'test')
    with open('runner-test.out') as f:
        assert 'Case #1: This is a joke' in f.readline()
        assert 'Case #2: 42' in f.readline()
    
            

    print 'TESTS PASSED'
        

if __name__ == '__main__':
    test()
