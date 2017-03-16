from os.path import join, isdir
from os import mkdir, makedirs
from io import StringIO
from sys import stdout

basedir = r'/home/david/scripts/codejam'
if not isdir(basedir):
    makedirs(basedir)

class CodeJam(object):
    def __init__(self, year, cround, problem, processor, debug=False):
        path = join(basedir, str(year), cround)
        if not isdir(path):
            makedirs(path)
        self.loc = path
        self.problem = problem
        self.debug = debug
        self.processor = processor
    def processtext(self, text):
        self.process(StringIO(text), stdout)
    def processfile(self, filename):
        with open(join(self.loc, filename)) as fin, \
             open(join(self.loc, filename + '.out'), 'w') as fout:
            self.process(fin, fout)
    def process(self, fin, fout):
        tests = int(fin.readline().strip())
        if self.debug:
            print('Total {} tests...'.format(tests))
        for test in range(tests):
            if self.debug:
                print('   Processing test {}...'.format(test))
            print('Case #{}: {}'.format(test+1, self.processor(fin)), file=fout)
